/*! \file       solution.h
 *  \author     ---=Put your name here=---
 *  \version    1.0
 *  \date       29.06.2022
 *
 *  Final Exam. Solution module. Put ALL the declarations and definitions right here.
 *  All the class methods must be defined here (do not put their in a separated
 *  file). If you need to create a non-member auxilliary function, put its defintion
 *  here as well.
 *
 *      → Provide your solution here and upload this only file to Ya.Contest! ←
 *
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

//========================================
//==========< Problem 1 [3pts] >==========

class Teacher
{
public:
    Teacher(const std::string& name)
        : _name(name)
    {
    }

    virtual ~Teacher() {}

    const std::string& getName() const { return _name; }
    virtual double calcWages() const = 0;
    virtual Teacher* cloneMe() const = 0;

protected:
    std::string _name;
};

class AssociateTeacher : public Teacher
{
public:
    AssociateTeacher(const std::string& name, int bonus)
        : Teacher(name), _bonus(bonus)
    {}
    static const int BASE_SALARY = 1500;
    int getBonus() const { return _bonus; }
    double calcWages() const override
    {
        return BASE_SALARY + _bonus;
    }
    Teacher* cloneMe() const override {
        return new AssociateTeacher(*this);
    }

protected:
    int _bonus;
};

class InvitedTeacher : public Teacher
{
public:
    InvitedTeacher(const std::string& name, int stuGroups)
        : Teacher(name), _stuGroups(stuGroups)
    {}
    static const int GROUP_TAX = 2000;
    int getStuGroups() const { return _stuGroups; }
    double calcWages() const override
    {
        return GROUP_TAX * _stuGroups;
    }
    Teacher* cloneMe() const override {
        return new InvitedTeacher(*this);
    }

protected:
    int _stuGroups;
};

//========================================
//==========< Problem 2 [3pts] >==========

class TArray {
public:
    size_t getSize() const
    {
        return _arr.size();
    }

    ~TArray()
    {
        clear();
    }

    AssociateTeacher* addAssociateTeacher(const std::string& name, int bonus)
    {
        AssociateTeacher* newTeacher = new AssociateTeacher(name, bonus);
        _arr.push_back(newTeacher);
        return newTeacher;
    }

    InvitedTeacher* addInvitedTeacher(const std::string& name, int stuGroups)
    {
        InvitedTeacher* newTeacher = new InvitedTeacher(name, stuGroups);
        _arr.push_back(newTeacher);
        return newTeacher;
    }

    Teacher* operator[](size_t index) const
    {
        if (index >= _arr.size()) {
            throw std::out_of_range("Index out of range");
        }
        return _arr[index];
    }
    TArray& operator=(const TArray& other) {
        if (this != &other) {
            clear();
            for (const auto& teacher : other._arr) {
                _arr.push_back(teacher->cloneMe());
            }
        }
        return *this;
    }
    TArray(const TArray& otherArray){
        for(int i=0;i<otherArray.getSize();i++){
            this->_arr.push_back(otherArray[i]->cloneMe());
        };
    }
    TArray() = default;

    friend std::ostream& operator << (std::ostream& os, const TArray& tArr);

protected:
    std::vector<Teacher*> _arr;

    void clear() {
        for (auto teacher : _arr) {
            delete teacher;
        }
        _arr.clear();
    }
};

std::ostream& operator << (std::ostream& os, const TArray& tArr)
{
    for (auto teacher : tArr._arr) {
        os << teacher->getName() << "," << teacher->calcWages() << '\n';
    }
    return os;
}

//========================================
//==========< Problem 3 [2pts] >==========

std::pair<int,int> totalWagesOfTopTeachers(const TArray& tArr, int minGroups, int minBonus)
{
    std::pair<int,int> res;
    for (size_t i = 0; i < tArr.getSize(); ++i) {
        Teacher* teacher = tArr[i];
        AssociateTeacher* associate = dynamic_cast<AssociateTeacher*>(teacher);
        if (associate && associate->getBonus() >= minBonus) {
            res.second += associate->calcWages();
        }
        InvitedTeacher* invited = dynamic_cast<InvitedTeacher*>(teacher);
        if (invited && invited->getStuGroups() >= minGroups) {
            res.first += invited->calcWages();
        }
    }
    return res;
}

//========================================
//==========< Problem 4 [2pts] >==========

    // TODO: Add all the stuff needed for the TArray class to comply with the Rule Of Three.
    // What do you have to add into the class for that?

//========================================

#endif
