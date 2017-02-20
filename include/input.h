#ifndef INPUT_H
#define INPUT_H

class Input
{
    public:
		Input();
        ~Input();

        bool        readKeyboard();
        const char  getKey();
    private:
        char        m_key;
};

#endif /* INPUT_H */