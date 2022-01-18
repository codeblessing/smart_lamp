#ifndef __SMARTLAMP_SETTING__
#define __SMARTLAMP_SETTING__

class Setting
{
public:
    Setting();
    void insert_next(char value);
    void remove_prev();
    void to_str(char * buffer);

    unsigned char __hour;
    unsigned char __minute;
    unsigned char __intensity;

private:
    char __property;
    char __index;
};

#endif // __SMARTLAMP_SETTING__
