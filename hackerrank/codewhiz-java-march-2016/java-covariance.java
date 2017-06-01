class Flower {
    public String whats_Your_Name() {
        return "I have many names and types";
    }
}
class Lily extends Flower {
    @Override
    public String whats_Your_Name() {
        return "Lily";
    }
}
class Jasmine extends Flower {
    @Override
    public String whats_Your_Name() {
        return "Jasmine";
    }
} 
class Lotus extends Flower {
    @Override
    public String whats_Your_Name() {
        return "Lotus";
    }
}
class State {
    public Flower your_National_Flower() {
        return new Flower();
    } 
}
class WestBengal extends State {
    @Override
    public Jasmine your_National_Flower() {
        return new Jasmine();
    } 
}
class Karnataka extends State {
    @Override
    public Lotus your_National_Flower() {
        return new Lotus();
    } 
}
class AndhraPradesh extends State {
    @Override
    public Lily your_National_Flower() {
        return new Lily();
    } 
}