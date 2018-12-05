#ifndef METRONOME_H
#define METRONOME_H

#include <QObject>
#include <chrono>

class Metronome : public QObject
{
    Q_OBJECT

private:
    bool running = false;
    std::chrono::steady_clock::time_point  previousTick;

public:
    explicit Metronome(QObject *parent = nullptr);
    ~Metronome();
    bool isRunning();

signals:
    void started();
    void stopped();
    void reportTickRate(int ticksPerMinute);

public slots:
    void receiveTick();
    void start();
    void stop();
};

#endif // METRONOME_H
