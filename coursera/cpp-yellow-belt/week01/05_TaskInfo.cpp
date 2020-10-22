#include <iostream>
#include <map>

using namespace std;


class TeamTasks {
 public:
  void AddNewTask(const string& person) {
    person_to_tasks[person][TaskStatus::NEW]++;
  }

  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
    return  person_to_tasks.at(person);
  }

  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
    map<TaskStatus, int> updated_tasks, untouched_tasks, updated_tasks_copy, tasks;
    tasks = person_to_tasks[person];
    int counter = task_count;

    while (counter--) {
      if (tasks[TaskStatus::NEW] > 0) {
        tasks[TaskStatus::NEW]--;
        updated_tasks[TaskStatus::IN_PROGRESS]++;
        continue;
      }
      if (tasks[TaskStatus::IN_PROGRESS] > 0) {
        tasks[TaskStatus::IN_PROGRESS]--;
        updated_tasks[TaskStatus::TESTING]++;
        continue;
      }
      if (tasks[TaskStatus::TESTING] > 0) {
        tasks[TaskStatus::TESTING]--;
        updated_tasks[TaskStatus::DONE]++;
        continue;
      }
    }
    updated_tasks_copy = updated_tasks;
    if (person_to_tasks[person][TaskStatus::NEW] && person_to_tasks[person][TaskStatus::NEW] - updated_tasks_copy[TaskStatus::IN_PROGRESS]) {
      untouched_tasks[TaskStatus::NEW] = person_to_tasks[person][TaskStatus::NEW] - updated_tasks_copy[TaskStatus::IN_PROGRESS];
    }
    if (person_to_tasks[person][TaskStatus::IN_PROGRESS] && person_to_tasks[person][TaskStatus::IN_PROGRESS] - updated_tasks_copy[TaskStatus::TESTING]) {
      untouched_tasks[TaskStatus::IN_PROGRESS] = person_to_tasks[person][TaskStatus::IN_PROGRESS] - updated_tasks_copy[TaskStatus::TESTING];
    }
    if (person_to_tasks[person][TaskStatus::TESTING] && person_to_tasks[person][TaskStatus::TESTING] - updated_tasks_copy[TaskStatus::DONE]) {
      untouched_tasks[TaskStatus::TESTING] = person_to_tasks[person][TaskStatus::TESTING] - updated_tasks_copy[TaskStatus::DONE];
    }

//    if (updated_tasks.count(TaskStatus::IN_PROGRESS)) {
//      untouched_tasks[TaskStatus::NEW] = tasks[TaskStatus::NEW];
//    }
//    if (updated_tasks.count(TaskStatus::TESTING)) {
//      untouched_tasks[TaskStatus::IN_PROGRESS] = tasks[TaskStatus::IN_PROGRESS];
//    }
//    if (updated_tasks.count(TaskStatus::DONE)) {
//      untouched_tasks[TaskStatus::TESTING] = tasks[TaskStatus::TESTING];
//    }

    for (auto [status, count] : tasks) {
      person_to_tasks[person][status] = count;
    }
    for (auto [status, count] : updated_tasks) {
      person_to_tasks[person][status] += count;
    }
    TasksInfo copy = person_to_tasks[person];
    for (auto& [status, count] : copy) {
      if (!count) {
        person_to_tasks.at(person).erase(status);
      }
    }
    return tie(updated_tasks, untouched_tasks);
  }

 private:
  map<string, map<TaskStatus, int>> person_to_tasks;
};
