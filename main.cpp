#include "MainWindow.h"
#include <QApplication>

#ifdef Q_OS_WIN
#  include <windows.h>
#  include <cstdio>
#endif
#include <iostream>

int main(int argc, char* argv[])
{
#ifdef Q_OS_WIN
    // ȷ�����Ż����һ������̨������ stdout/stderr �󶨹�ȥ
    if (AttachConsole(ATTACH_PARENT_PROCESS) == 0) {
        AllocConsole();
    }
    FILE* fp = nullptr;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);
#endif

    // ���ֱ���� fprintf / cerr ���
    fprintf(stderr, "C stderr works?\n");
    std::cerr << "C++ cerr works?" << std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    fprintf(stderr, "Window shown\n");
    std::cerr << "App entering event loop" << std::endl;

    return a.exec();
}
