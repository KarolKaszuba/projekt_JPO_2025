#include "weather_client.h"

using namespace std;

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

WeatherClient ::WeatherClient() {};

string WeatherClient ::getWeatherData(double latitude, double longitude)
{
    try
    {
        net::io_context ioc;
        tcp::resolver resolver(ioc);
        tcp::socket socket(ioc);

        auto const results = resolver.resolve("api.open-meteo.com", "80");
        net::connect(socket, results.begin(), results.end());

        // tworzenie stringa ( zapytania HTTP ) do API
        string requested_Data = "/v1/forecast?latitude=52.400276&longitude=16.955308&current=temperature_2m,precipitation,weather_code,surface_pressure,wind_speed_10m";

        http::request<http::string_body> req(http::verb::get, requested_Data, 11);

        req.set(http::field::host, "api.open-meteo.com");
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        http::write(socket, req);

        beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(socket, buffer, res);

        // cout << res << endl;
        beast::error_code ec;
        socket.shutdown(tcp::socket::shutdown_both, ec);

        /**
         * res to bufor danych buffers_to_string konwertuje dane do stringa
         * metoda data() zwraca dostep do surowych danych
         * body() zwraca referencję do obiektu ktory przechpwuje dane
         */
        return beast::buffers_to_string(res.body().data());
    }
    catch (std::exception const &e)
    {
        cerr << "Wystąpił wyjątek: " << e.what() << endl;
        return "";
    }
};