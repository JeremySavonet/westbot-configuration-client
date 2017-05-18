#ifndef CONFIGURATIONCLIENT_HPP
#define CONFIGURATIONCLIENT_HPP

class QString;

namespace WestBot {

class ConfigurationClient
{
public:
    ConfigurationClient();

    bool connect( const QString& ip );

private:
    bool _isConnected;
};

}

#endif // CONFIGURATIONCLIENT_HPP
