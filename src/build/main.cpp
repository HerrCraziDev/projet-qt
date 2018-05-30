#include "MainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    /*Simulation terreplate(10,10,32,100,0.2,42);
    //SimulationController illuminatis(&terreplate);

    //illuminatis.attach(&terreplate);
    //illuminatis.launch();

    while ( terreplate.countEntities( {EType::Animal, EType::Predator, EType::Prey} ) )
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        terreplate();
    }

    //illuminatis.stop();

    return 0;*/
}
