package com.course.buildings;
public class Building
{
    protected float sqFeet;
    protected int stories;
    public void setSqFeet(float ft)
    {
        sqFeet = ft;
    }
    public void setStories(int floors)
    {
        stories = floors;
    }
    public float getSqFeet()
    {
        return sqFeet;
    }
    public int getStories()
    {
        return stories;
    }
}