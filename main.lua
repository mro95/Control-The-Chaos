function love.load()
    love.graphics.setBackgroundColor( 255,255,255 )

    fonts = {}
    fonts[16] = love.graphics.newFont("res/SF Intermosaic B.ttf", 16)
    fonts[24] = love.graphics.newFont("res/SF Intermosaic.ttf", 24)
    fonts[32] = love.graphics.newFont("res/SF Intermosaic.ttf", 32)
    fonts[48] = love.graphics.newFont("res/SF Intermosaic.ttf", 48)
    fonts[64] = love.graphics.newFont("res/SF Intermosaic.ttf", 64)
end

function love.update(dt)

end

function love.draw()
    love.graphics.setFont(fonts[48])
    w = love.graphics.getWidth() /2
    h = 0;
    --love.graphics.translate( w, h );

    love.graphics.setColor(255, 0, 0);
    love.graphics.print("Control The Chaos",0,0,0)
end

function love.keypressed(key)
    if key == "escape" then
        love.event.quit()
    end
end
