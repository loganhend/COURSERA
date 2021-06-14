#include <iostream>
#include <string>
#include <tuple>
#include <map>
using namespace std;


class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
	  return team_tasks.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
	  TasksInfo& person_tasks = team_tasks[person];
	  person_tasks[TaskStatus::NEW] += 1;
  }


  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
	  TasksInfo new_task;
	  TasksInfo untouched_tasks;
	  TasksInfo& tasks = team_tasks[person];
	  /*for (int i=1; i<4; i++) {
		  auto pred = static_cast<TaskStatus> (i - 1);
		  auto curr = static_cast<TaskStatus> (i);
		  new_task[curr] = min(task_count, tasks[pred]);
		  cout << min(task_count, tasks[pred]) << '-';
		  task_count -= new_task[curr];
		  untouched_tasks[pred] = max(tasks[pred] - new_task[curr], 0);
		  cout << max(tasks[pred] - new_task[curr], 0) << endl;
		  tasks[pred] -= new_task[curr];
		  tasks[curr] += new_task[curr];
	  }
	  */
	  for (int i = 1; i < 4; ++i) {
	        auto pred = static_cast<TaskStatus> (i - 1);
	        auto curr = static_cast<TaskStatus> (i);
	        new_task[curr] = min(task_count, tasks[pred]);
	        task_count -= new_task[curr];
	      }
	      for (int i = 1; i < 4; ++i) {
	        auto pred = static_cast<TaskStatus> (i - 1);
	        auto curr = static_cast<TaskStatus> (i);
	        untouched_tasks[pred] = max(tasks[pred] - new_task[curr], 0);
	      }
	      for (int i = 1; i < 4; ++i) {
	        auto pred = static_cast<TaskStatus> (i - 1);
	        auto curr = static_cast<TaskStatus> (i);
	        tasks[pred] -= new_task[curr];
	        tasks[curr] += new_task[curr];
	      }
	  for (int i=0;i<4;i++) {
	  	  int cnt_tasks = tasks[TaskStatus(i)];
		  if (cnt_tasks == 0) {
			  tasks.erase(TaskStatus(i));
		  }
		  cnt_tasks = new_task[TaskStatus(i)];
		  if (cnt_tasks == 0) {
			  new_task.erase(TaskStatus(i));
		  }
		  cnt_tasks = untouched_tasks[TaskStatus(i)];
		  if (cnt_tasks == 0) {
			  untouched_tasks.erase(TaskStatus(i));
		  }
	  }
	  untouched_tasks.erase(TaskStatus::DONE);
	  return {new_task,untouched_tasks};
  }
private:
  map<string,TasksInfo> team_tasks;
};
