

public class Neuron {

    private int id;
    private Object Value; //Definition

    private double[] Weight;

    public  Neuron(int id){
        this.id = id;
    }

    public int GetId() {
        return this.id;
    }

    public double[] GetWeight() {
        return this.Weight;
    }

    public void SetWeight(double[] Weight) {
        this.Weight = new double[Weight.length];
        this.Weight = Weight;
    }

}
