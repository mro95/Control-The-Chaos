#ifndef Text_H
    #define Text_H

class Text
{
    public:

        void init()
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, 800, 600, 0, -1.0, 1.0);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glEnable(GL_TEXTURE_2D);
            glEnable(GL_BLEND);
            glDisable(GL_LIGHTING);
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        }

        void render(const char *text, float x, float y) 
        {

            glClear(GL_COLOR_BUFFER_BIT);
    
        }
};
#endif
