public class DogLauncher {
    public static void main(String[] args)
    {
        Dog maya = new Dog();
        maya.weightInPounds = 100;
        maya.makeNoise();

        Dog yapster = new Dog(5);
        yapster.makeNoise();

        Dog leon = new Dog(150);
        Dog shadow = new Dog(5);

        Dog larger = Dog.maxDog(shadow, leon);
        larger.makeNoise();

        System.out.println(Dog.binomen);
    }
}