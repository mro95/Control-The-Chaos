function love.load()
    local stime = love.timer.getTime()
    --love.graphics.setBackgroundColor( 255,0,0 )

    fonts = {}
    fonts[16] = love.graphics.newFont("res/SF Intermosaic B.ttf", 16)
    fonts[24] = love.graphics.newFont("res/SF Intermosaic.ttf", 24)
    fonts[32] = love.graphics.newFont("res/SF Intermosaic.ttf", 32)
    fonts[48] = love.graphics.newFont("res/SF Intermosaic.ttf", 48)
    fonts[64] = love.graphics.newFont("res/SF Intermosaic.ttf", 64)

    --logo = love.graphics.newImage("res/logo.png")
    logo = love.graphics.newImage("res/logo-white.png")

    -- music
    music = love.audio.newSource("res/music.mp3", "static")
    love.audio.play(music)

    intro = {}
    intro[1] =
    {
        rekts = 
        {
            {
                r = 254,
                g = 225,
                b = 0,
                h = 1.5
            },

            {
                r = 170,
                g = 181,
                b = 0,
                h = 2.5
            },

            {
                r = 85,
                g = 137,
                b = 0,
                h = 6.5
            }
        },
        bg = { r = 255, g = 0, b = 0 }
    }
    intro[2] =
    {
        rekts = 
        {
            {
                r = 254,
                g = 0,
                b = 0,
                h = 1.5
            },

            {
                r = 171,
                g = 9,
                b = 3,
                h = 2.5
            },

            {
                r = 85,
                g = 21,
                b = 9,
                h = 6.5
            }
        },
        bg = { r = 151, g = 0, b = 255 }
    }
    intro[3] =
    {
        rekts = 
        {
            {
                r = 0,
                g = 190,
                b = 90,
                h = 1.5
            },

            {
                r = 0,
                g = 190,
                b = 100,
                h = 2.5
            },

            {
                r = 0,
                g = 200,
                b = 90,
                h = 6.5
            }
        },
        bg = { r = 20, g = 0, b = 95 }
    }

    dt_count = 0;
    intro_count = 1;



end

function love.update(dt)
    dt_count = dt_count + dt

    if dt_count > 1 then
        dt_count = 0
        if intro_count == 3 then
            intro_count = 1
        else
            intro_count = intro_count + 1
        end
    end
end

function love.draw()

    ww = love.graphics.getWidth()
    wh = love.graphics.getHeight()
    
    --
    -- love.graphics.setColor(254, 225, 0)
    -- love.graphics.rectangle("fill", 0, 0, ww, wh/1.5 )
    -- love.graphics.setColor(170, 181, 0)
    -- love.graphics.rectangle("fill", 0, 0, ww, wh/2.5 )
    -- love.graphics.setColor(85, 137, 0)
    -- love.graphics.rectangle("fill", 0, 0, ww, wh/6 )
    --

    i = intro_count
    
    love.graphics.setBackgroundColor( intro[i].bg.r, intro[i].bg.g, intro[i].bg.b)
    for key,v in pairs(intro[i].rekts) do
        love.graphics.setColor(v.r, v.g, v.b)
        love.graphics.rectangle("fill", 0, 0, ww, wh/v.h )
    end


    love.graphics.setColor(255, 255, 255);
    love.graphics.setFont(fonts[32])
    love.graphics.print("Press spacebar to continue",ww/2-380,wh/2+200,0,1,1)
    --
    love.graphics.setColor(255, 255, 255)
    love.graphics.translate( ww/2, wh/2 );


    -- Logo
    logoWidth = logo:getWidth()
    logoHeight = logo:getHeight()
    love.graphics.draw(logo, 0,-50,0,1,1,logoWidth / 2,logoHeight / 2)
    
end

function love.keypressed(key)
    if key == "escape" then
        love.event.quit()
    end
end

function updatecounter()
    intro_count = intro_count + 1
end
