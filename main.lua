function love.load()
    love.graphics.setBackgroundColor( 255,255,255 )
end
 
function love.update(dt)
     
end
 
function love.draw()
    w = love.graphics.getWidth() /2
    h = love.graphics.getHeight() /2
    love.graphics.translate( w, h );

    love.graphics.setColor(0, 0, 0);
    love.graphics.print("Hello World!",0,0)
    love.graphics.circle("line", 0, 0, w/2, 128)
end

function love.keypressed(key)
    if key == "escape" then
        love.event.quit()
    end
end
