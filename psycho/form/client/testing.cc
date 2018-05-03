#include "client.ih"

    // when ratings are already available, then throw false, resulting in
    // the /index.html page being shown.

void Client::testing()
{
    WIPdata wipData{ "1", "es" };

    LockGuard lg = wipData.read();

    Report report{ wipData };
    report.fsplot();
    report.latex();

    g_log << "Going home" << endl;

    d_display.homePage();
}


