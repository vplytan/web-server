#include "../builders/Request.hpp"
#include "Handler.hpp"

class TextHandler: public Handler {
public:
	Response* do_handle(Request* aRequest);
};


