import com.course.buildings.School;
import com.course.buildings.House;
import com.course.buildings.Building;
public class FinalBuildings
{
    public static void main(String[] args)
    {
        Building B = new Building();
        House H = new House();
        School S = new School();
        B.setSqFeet(10000);
        B.setStories(1);
        H.setSqFeet(1800);
        H.setStories(2);
        H.setBedrooms(3);
        H.setBaths(2);
        S.setSqFeet(3500);
        S.setStories(3);
        S.setClassrooms(48);
        S.setGradeLevel("High");
        System.out.println("The Building:\n" +
                B.getSqFeet() + " square feet\n" +
                B.getStories() + " stories\n");
        System.out.println("\nThe House:\n" +
                H.getSqFeet() + " square feet\n" +
                H.getStories() + " stories\n" +
                H.getBedrooms() + " bedrooms and " +
                H.getBaths() + " bathrooms\n");
        System.out.println("\nThe School:\n" +
                S.getSqFeet() + " square feet\n" +
                S.getStories() + " stories\n" +
                S.getClassrooms() + " classrooms. It's a " +
                S.getGradeLevel() + " school\n");
    }
}