#include "task.ih"

Task::Task(task_function isFunction, char const *label)
:
    d_is_function(isFunction),
    d_taskname(label),
    d_count(0)
{ }