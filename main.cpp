#include <iostream>
#include <weather_client.h>

using namespace std;

int main()
{
    /**
     *  inicjalizuje obiekt WeatherClient i ustawiam zmienne szerokości i długości geograficznej.
     * @note
     *       Szerokość geograficzna odpowiada równikowi (N/S), a długość geograficzna odpowiada południkowi zerowemu (E/W).
     *       Dodatnie wartości szerokości geograficznej oznaczają półkulę północną (N), natomiast ujemne wartości oznaczają półkulę południową (S).
     *       Dodatnie wartości długości geograficznej oznaczają półkulę wschodnią (E), natomiast ujemne wartości oznaczają półkulę zachodnią (W).
     */

    WeatherClient weatherClient_1;
    double latitude = 52.400276;
    double longitude = 16.955308;

    string response_for_Client_1 = weatherClient_1.getWeatherData(latitude, longitude);

    if (response_for_Client_1 == "")
    {
        cout << "Błąd pobierania danych." << endl;
    }
    else
    {
        cout << response_for_Client_1 << endl;
    }
    return 0;
}