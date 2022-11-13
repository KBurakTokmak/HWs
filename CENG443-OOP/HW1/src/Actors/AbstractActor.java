package Actors;

import Util.AABB;

import java.awt.*;

// Meta Actor Class
// Everything in the game is an actor
public abstract class AbstractActor extends AABB
{
    // TODO:

    public void update(float deltaT, Graphics2D g)
    {
        // TODO:
    }

    public abstract boolean isDead();
}
