#include "web.hpp"
#include <cpr/cpr.h>

Web::Response Web::download_url(const std::string& url) {
    cpr::SslOptions sslOpts = cpr::Ssl(cpr::ssl::ALPN(false), cpr::ssl::NPN(false), cpr::ssl::VerifyHost(false), cpr::ssl::VerifyPeer(false), cpr::ssl::VerifyStatus(false));
    cpr::Response r = cpr::Get(cpr::Url(url), sslOpts);
    return Response{r.text, r.status_code};
}
