class Semaphore
{
    public:

    template<typename Function, typename ...Params>
    bool wait(Function fun, Params &&...params);
};


template<typename Function, typename ...Params>
bool Semaphore::wait(Function fun, Params &&...params)
{
    unique_lock<mutex> lock(d_mutex);

    while (!d_count)
        d_condition.wait(lock);

    --d_count;

    return fun(std::forward<Params>(params)...);
}

