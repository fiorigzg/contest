
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

// task 1
Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
: text(text), date(date), workloads(workloads) {}

struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Worker::Worker(const std::string& name, const std::string& login, int maxLoad)
{
    Worker::name = name;
    Worker::login = login;
    Worker::maxLoad = maxLoad;
}


// task 2
int Task::getTotalLoad() const
{
    uint res = 0;
    for(const Task::Workload& el : Task::workloads) {
        res += el.second;
    }

    return res;
}


bool tasksCompare(const Task& task1, const Task& task2)
{
    if(task1.getTotalLoad() != task2.getTotalLoad())
        return task1.getTotalLoad() < task2.getTotalLoad();
    
    if(task1.date != task2.date)
        return task1.date < task2.date;
    
    return task1.text < task2.text;
}

inline bool operator<(const Task& task1, const Task& task2)
{
    return tasksCompare(task1, task2);
}

// task 3
void sortTasks(std::vector<Task>& tasks)
{
    // sort(tasks.begin(), tasks.end(), tasksCompare);
    sort(tasks.begin(), tasks.end());
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    uint res = 0;
    for(const Task& task : allTasks) {
        for(const Task::Workload& workload : task.workloads) {
            if(worker.login == workload.first)
                res += workload.second;
        }
    }
    return res;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    for(const Task::Workload& workload : newTask.workloads) {
        for(const Worker& worker : workers) {
            if(worker.login == workload.first) {
                if(getWorkerLoad(tasks, worker) + workload.second > worker.maxLoad)
                    throw std::runtime_error("Overworked");
            }
        }
    }

    tasks.push_back(newTask);
}

// task 6
void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    std::map<std::string, int> overworkers;
    tasks.push_back(newTask);

    for(const Worker& worker : workers) {
        int overwork = getWorkerLoad(tasks, worker) - worker.maxLoad;
        // std::cout << worker.login << " " << getWorkerLoad(tasks, worker) << " " << worker.maxLoad << std::endl;
        if(overwork > 0)
            overworkers.insert({worker.login, overwork});
    }

    std::string exceptionText = "Overworked: ";
    size_t overworkerIndex = 0;
    for(const std::pair<std::string, int>& overworker : overworkers) {
        if(overworkerIndex != 0)
            exceptionText += ", ";
        exceptionText += overworker.first + " by " + std::to_string(overworker.second);
        ++overworkerIndex;
    }


    if(!overworkers.empty()) {
        tasks.pop_back();
        throw std::runtime_error(exceptionText);
    }
}
