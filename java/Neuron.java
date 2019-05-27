

public class Neuron {

    private int id;

    private float[] Weight;

    public  Neuron(int id){
        this.id = id;
    }

    public int GetId() {
        return this.id;
    }

    public float[] GetWeight() {
        return this.Weight;
    }

    public void SetWeight(float[] Weight) {
        this.Weight = new float[Weight.length];
        this.Weight = Weight;
    }
}
