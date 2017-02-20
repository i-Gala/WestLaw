#ifndef _ANIMATIONMANAGER_H
#define _ANIMATIONMANAGER_H

class HUD;
class AnimationManager
{
    public:
        AnimationManager();
        AnimationManager(HUD *);
        ~AnimationManager();
        
        void        AnimationWaves();
        void        incCount();

        int         getCount();
        bool        getActive();
    private:
		HUD        *m_hud;
        int         m_count;
        bool        m_delete;
        bool        m_active;

        const int   MAX_TIME_TEXT = 20;
        const int   MAX_WAVES = 60;
};

#endif /* _ANIMATIONMANAGER_H */

