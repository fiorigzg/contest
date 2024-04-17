#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>


enum class CitationType
{
    WebPage,
    Article
};

class Citation
{
public:
    Citation(const std::string& title, int year)
        : _title(title), _year(year)
    {
    }

    virtual ~Citation() {}
    virtual void printCitation(std::ostream& ostr) const = 0;
    virtual std::string getInlineCitation() const = 0;
    virtual std::string getIdentifier() const = 0;
    virtual CitationType getType() const = 0;
protected:
    std::string _title;
    int _year;
};


class WebPage : public Citation
{
public:
    WebPage(const std::string& title, int year, const std::string& url)
        : Citation(title, year),
          _url(url)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "URL: " << _url << std::endl;
    }

    std::string getInlineCitation() const override
    {
        std::string res = "[Web page, " + std::to_string(_year) + "]";
        return res;
    }

    std::string getIdentifier() const override
    {
        return _title;
    }

    CitationType getType() const override
    {
        return CitationType::WebPage;
    }

protected:
    std::string _url;
};


class PublishedWork : public Citation
{
public:
    PublishedWork(const std::string& title, int year, const std::string& firstname, const std::string& lastname)
        : Citation(title, year),
          _firstname(firstname), _lastname(lastname)
    {
    }

protected: 
    std::string _firstname;
    std::string _lastname;
};


class Article : public PublishedWork
{
public: 
    Article(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& journal)
        : PublishedWork(title, year, firstname, lastname),
          _journal(journal)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "Author: " << _firstname << " " << _lastname << std::endl;
        ostr << "Journal: " << _journal << std::endl;
    }

    std::string getInlineCitation() const override
    {
        std::string res = "[" + _lastname + ", " + std::to_string(_year) + "]";
        return res;
    }

    std::string getIdentifier() const override
    {
        return _lastname;
    }

    CitationType getType() const override
    {
        return CitationType::Article;
    }

protected:
    std::string _journal;
};


// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations, CitationType type, const std::map<std::string, std::string> data)
{
    Citation* citationToAdd;
    // your code
    if(type == CitationType::WebPage)
    {
        citationToAdd = new WebPage(data.at("title"), std::stoi(data.at("year")), data.at("url"));
    }
    if(type == CitationType::Article)
    {
        citationToAdd = new Article(data.at("title"), std::stoi(data.at("year")), data.at("firstname"), data.at("lastname"), data.at("journal"));
    }
    citations[data.at("key")] = citationToAdd;
    return citationToAdd;
}


// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
    size_t start = text.find('{');
    size_t end = text.find('}') - start;
    while(start != std::string::npos && end != std::string::npos) {
        std::string citationKey = text.substr(start, end + 1);
        std::string citationReplacement = citations.at(citationKey)->getInlineCitation();
        text = text.substr(0, start) + citationReplacement + text.substr(end + start + 1, text.size());

        start = text.find('{');
        end = text.find('}') - start;
    }
}


// task 5
void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::set<std::string> printed;
    
    size_t start = text.find("{");
    size_t end = text.find("}") - start;
    while(start != std::string::npos && end != std::string::npos)
    {
        std::string citationKey = text.substr(start, end + 1);
        if(printed.find(citationKey) == printed.end()) {
            std::cout << printed.size() + 1 << '.' << std::endl;
            citations.at(citationKey)->printCitation(std::cout);
            printed.insert(citationKey);
        }

        start = text.find("{", start + 1);
        end = text.find("}", start) - start;
    }
}


// task 6
// you may modify classes in any way you want to solve this task
// you may add additional functions
void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::map<std::string, std::string> articleKeys;
    std::map<std::string, std::string> webPageKeys;
    for(const std::pair<std::string, Citation*> citation : citations)
    {
        if(citation.second->getType() == CitationType::Article) {
            articleKeys[citation.second->getIdentifier()] = citation.first;
        }
        if(citation.second->getType() == CitationType::WebPage) {
            webPageKeys[citation.second->getIdentifier()] = citation.first;
        }
    }

    std::map<std::string, size_t> citationIndexes;
    size_t index = 1;
    for(const std::pair<std::string, std::string> articleKey : articleKeys)
    {
        citationIndexes[articleKey.second] = index;
        ++index;
    }
    for(const std::pair<std::string, std::string> webPageKey : webPageKeys)
    {
        citationIndexes[webPageKey.second] = index;
        ++index;
    }

    size_t start = text.find('{');
    size_t end = text.find('}') - start;
    while(start != std::string::npos && end != std::string::npos) {
        std::string citationKey = text.substr(start, end + 1);
        std::string citationReplacement = "[" + std::to_string(citationIndexes[citationKey]) + "]";
        text = text.substr(0, start) + citationReplacement + text.substr(end + start + 1, text.size());

        start = text.find('{');
        end = text.find('}') - start;
    }
}

#endif
