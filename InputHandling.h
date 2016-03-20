//
//  InputHandling.h
//  PA4
//

#ifndef PA4_InputHandling_h
#define PA4_InputHandling_h

class InvalidInput
{
public:
    InvalidInput (char* in_ptr): msg_ptr (in_ptr) {}
    const char* const msg_ptr;
private:
    InvalidInput();
};

#endif
