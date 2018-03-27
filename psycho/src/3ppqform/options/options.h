#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>

class Options
{
    std::string d_base;
//    std::string d_users;
//    std::string d_states;
//    std::string d_daemons;
//    std::string d_objects;
//    std::string d_globals;
    std::string d_log;

//    std::string d_toMonitor;
//    std::string d_fromMonitor;
//
//    int d_toMonitorFd;
//    int d_fromMonitorFd;

    public:
        Options();
        Options(std::string const &base);

//        std::string const &users() const;
//        std::string const &states() const;
//        std::string const &daemons() const;
//        std::string const &objects() const;
//        std::string const &globals() const;
        std::string const &log() const;
        std::string const &base() const;

//        std::string const &toMonitor() const;
//        std::string const &fromMonitor() const;
//
//        int toMonitorFd() const;
//        int fromMonitorFd() const;
//
//        size_t firstDaemonState() const;

    private:
        void initialize(std::string const &baseDir);

        int fifoFd(std::string const &fifo);
        int makeFifo(std::string const &fifo);
};

//inline std::string const &Options::users() const
//{
//    return d_users;
//}
//
//inline std::string const &Options::states() const
//{
//    return d_states;
//}
//
//inline std::string const &Options::daemons() const
//{
//    return d_daemons;
//}
//
//inline std::string const &Options::objects() const
//{
//    return d_objects;
//}
//
//inline std::string const &Options::globals() const
//{
//    return d_globals;
//}

inline std::string const &Options::log() const
{
    return d_log;
}

inline std::string const &Options::base() const
{
    return d_base;
}

//inline std::string const &Options::toMonitor() const
//{
//    return d_toMonitor;
//}
//        
//inline std::string const &Options::fromMonitor() const
//{
//    return d_fromMonitor;
//}
//        
//inline int Options::toMonitorFd() const
//{
//    return d_toMonitorFd;
//}
//        
//inline int Options::fromMonitorFd() const
//{
//    return d_fromMonitorFd;
//}
//
//inline size_t Options::firstDaemonState() const
//{
//    return 0;           // recompile daemonadmin/init.cc after changing this
//}
        
        
#endif
