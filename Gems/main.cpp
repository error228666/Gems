#include "gems.hpp"
#include "gem.hpp"



int main()
{
    srand(time(0));
   
    sf::RenderWindow window(sf::VideoMode(window_size, window_size), "SFML works!");
    window.setFramerateLimit(60);
   
    GemsField gems;
    
    

    Clock clc;
   
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
            {
                if (gems.deleting_stage == 0)
                {
                    gems.swap_stage = SwapStage::Compression;
                    gems.choosing(window, clc);
                }
            }
            
        }
        if (gems.chosen2 != Vector2i(-1, -1))
            gems.swap_chosen_gems(window, clc);
        window.clear();
      
        gems.draw(window);
        window.display();
        if (gems.swap_stage == SwapStage::None)
            gems.update(clc); 
    }
    
    return 0;
}