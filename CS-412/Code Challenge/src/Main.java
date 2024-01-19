public class Main {
    public static void main(String[] args) {
        Pet[] pets = new Pet[3];

        Dog dog = new Dog();
        Cat cat = new Cat();
        Goat goat = new Goat();

        dog.setName("Fido");
        cat.setName("Friz");
        goat.setName("Billy");

        pets[0] = dog;
        pets[1] = cat;
        pets[2] = goat;

        for (Pet p : pets) {
            p.speak();
            p.sleep();
        }
    }
}