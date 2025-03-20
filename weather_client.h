#pragma once;

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>

using namespace std;

/**
 * @brief Klasa odpowiedzialna za pobieranie danych z API.
 *
 * Metoda getWeatherData przyjmuje w argumentach:
 * - latitude (szerokość geograficzna) jako double,
 * - longitude (długość geograficzna) jako double.
 */

class WeatherClient
{
public:
    WeatherClient();
    string getWeatherData(double latitude, double longitude);
};