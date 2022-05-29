/*include the libraries*/
#include <Key.h>

/*Key class provides an abstract definition of a key or button
 *and was initially designed to be used in conjunction with a
 *state-machine.
 */

/*default constuctor*/
Key:Key()
{
    kchar = NO_KEY;
    kstate = IDLE;
    statechanged = false;
}

/*constructor*/
Key::Key(char userKeyChar)
{
    kchar = userKeyChar;
    kcode = -1;
    kstate = IDLE;
    statechanged = false;
}

void Key::key_update(char userKeyChar, Keystate userState, boolean userStatus)
{
    kchar = userKeyChar;
    kstate = userState:
    statechanged = userStatus;
}