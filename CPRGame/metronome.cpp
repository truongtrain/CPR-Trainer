#include "metronome.h"
#include <QDebug>
#include <ctime>
#include <chrono>

Metronome::Metronome(QObject *parent) : QObject(parent)
{
    qDebug() << "Connection made.";
}

Metronome::~Metronome()
{}

bool Metronome::isRunning()
{
    return running;
}

void Metronome::setDesiredRate(int ticksPerMinute)
{
    desiredRateTicksPerMinute = ticksPerMinute;
}

void Metronome::setDesiredTolerance(int ticksPerMinute)
{
    desiredRateAccetableError = ticksPerMinute;
}

int Metronome::receiveTick()
{
    // Metronome cannot receive a tick if it is not running.  Start the metronome.
    if (!running)
    {
        start();
        return 0; // Metronome is not running.
    }

    // Get the currect time.
    std::chrono::steady_clock::time_point newTick = std::chrono::steady_clock::now();
    // Subtract previous time from current time.
    std::chrono::duration<double> timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(newTick - previousTick);

    previousTick = newTick; // Set the previous tick for next time 'receiveTick()' is called

    double timeElapsedSeconds = timeSpan.count();

    // Adding 0.5 helps for rounding.  Normally, any double x.0 to x.9999 always rounds down to
    //   x when converting to an int.  Now, x.0 to x.5 rounds DOWN to x, while anything larger than
    //   x.5 up to x.9999 rounds UP to x+1
    int rateTicksPerMinute = 60/(timeElapsedSeconds) + 0.5;

    if ((rateTicksPerMinute > desiredRateTicksPerMinute + desiredRateAccetableError) ||
            (rateTicksPerMinute < desiredRateTicksPerMinute - desiredRateAccetableError))
    {
        tickRateWithinTolerance = false;
    }
    else
    {
        tickRateWithinTolerance = true;
    }

    return rateTicksPerMinute;
}

bool Metronome::isTickRateWithinTolerance()
{
    return tickRateWithinTolerance;
}

void Metronome::start()
{
    running = true;
    previousTick = std::chrono::steady_clock::now();
    emit started();
}

void Metronome::stop()
{
    running = false;
    emit stopped();
}
