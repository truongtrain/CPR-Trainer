#ifndef METRONOME_H
#define METRONOME_H

#include <QObject>
#include <chrono>

/**
 * This is the metronome class. The metronome keeps track of whether the time
 * interval (rate) between events occurs within a given range
 */
class Metronome : public QObject
{
    Q_OBJECT

private:
    bool running = false;
    bool tickRateWithinTolerance = true;
    int desiredRateTicksPerMinute = 60; // Default is 60.
    int desiredRateAccetableError = 10;  // Default is 10.
    std::chrono::steady_clock::time_point  previousTick;

public:
    explicit Metronome(QObject *parent = nullptr);
    ~Metronome();

    /**
     * Returns whether the metronome is running
     */
    bool isRunning();

    /**
     * Set the desired rate in ticks per minute
     */
    void setDesiredRate(int ticksPerMinute);

    /**
     * Set the tolerance (error from the desired rate) in ticks per minute that is acceptable
     */
    void setDesiredTolerance(int ticksPerMinute);

    /**
     * Returns the measured tick rate
     */
    int receiveTick();

    /**
     * Returns whether the measured tick rate is within the tolerance of the desired rate
     */
    bool isTickRateWithinTolerance();

signals:
    void started();
    void stopped();

public slots:
    void start();
    void stop();
};

#endif // METRONOME_H
