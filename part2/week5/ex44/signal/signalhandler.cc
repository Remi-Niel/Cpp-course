#include "signal.ih"

// this function receives signums and calls the appropriate handlers 
void Signal::sigmapHandler(int signum)
{
    // getting the map inside the singleton is a hassle, is a private static 
    // data member singleton instance in Signal preferable?
    Signal &sig_ptr = Signal::accessSignal();
    auto &map_ref = sig_ptr.d_sigmap;

    // go through all map entries associated with the signum and call their
    // objects' handle functions
    for (auto it = map_ref.find(signum); it != map_ref.end(); ++it)
        it->second.handle(signum);
}