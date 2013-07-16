#include "../builders/Request.hpp"
#include "Handler.hpp"

class TextHandler: public Handler {
public:
	char* doHandle(const Request &aRequest);
};


