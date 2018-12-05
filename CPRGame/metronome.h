#ifndef METRONOME_H
#define METRONOME_H

#include <QObject>
#include <chrono>

class Metronome : public QObject
{
    Q_OBJECT

private:
    bool running = false;
    int desiredRateTicksPerMinute = 60; // Default is 60.
    int desiredRateAccetableError = 10;  // Default is 10.
    std::chrono::steady_clock::time_point  previousTick;

public:
    explicit Metronome(QObject *parent = nullptr);
    ~Metronome();
    bool isRunning();
    void setDesiredRate(int ticksPerMinute);
    void setDesiredTolerance(int ticksPerMinute);

signals:
    void started();
    void stopped();
    void reportTickRate(int ticksPerMinute);
    void tickRateWithinTolerance();
    void tickRateOutsideTolerance();

public slots:
    void receiveTick();
    void start();
    void stop();
};

#endif // METRONOME_H
