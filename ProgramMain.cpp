#include"ProgramMain.h"








class Object{   
    private: 

    public:
        std::vector<double> coordinates = {0,0,0};
        std::vector<double> velocity = {0,0,0};
        bool fixed = false;
        double mass = 0;
        double charge = 0;
        double magneticism = 0;

        std::vector<double> totalForce = {0,0,0};

        Object(bool Fixed, std::vector<double> xyz, std::vector<double> vxyz, double Mass, double Charge, double Magneticism){
            fixed = Fixed;
            coordinates = xyz;
            velocity = vxyz;
            mass = Mass;
            charge = Charge;
            magneticism = Magneticism;
        }
        /*Object(bool Fixed, std::vector<double> xyz, double Mass=1, double Charge, double Magneticism){
            fixed = Fixed;
            coordinates = xyz;
            mass = Mass;
            charge = Charge;
            magneticism = Magneticism;
        }*/
};



class Field{
    private:
        bool globalForce;
};

class GravityField: public Field{
    private:
        
    public:
        std::vector<double> strength;

        GravityField(double Strength){
            strength = {0,0,Strength};
        }
};

class MagneticField: public Field{

};


std::vector<double> calculateForce(Object object, GravityField field){
    std::vector<double> force = {0,0,0};
    if(object.mass != 0){
        for (int i = 0; i < 3; i++)
        {
            force[i] = field.strength[i] * object.mass;
            //std::cout << force[i] << std::endl;
        }
        
    }
    return force;
};

std::vector<double> calculateForce(Object object, MagneticField field){

};


class World{
    private:
        std::vector<Object> objects;
        std::vector<GravityField> gravityFields;
        std::vector<MagneticField> magneticFields;
        double stepSize = 0;

    public:
        World(bool gravity,double gravitystrength, double stepInterval){
            if(gravity){
                gravityFields.push_back(GravityField(gravitystrength));
            }
            stepSize = stepInterval;
        }
        void insertObject(Object x){
            objects.push_back(x);
        }
        void update(){
            for(auto &o: objects){
                for(auto f: gravityFields){
                    o.totalForce = calculateForce(o, f);
                    
                    
                }
                
            }
            for(auto &o: objects){
                for (auto x :o.totalForce)
                    {
                        std::cout << x << std::endl;
                    }
            }
            for(auto &o: objects){
                for(int i = 0; i < 3; i++){
                    o.coordinates[i] += o.velocity[i] * stepSize;
                    o.velocity[i] += o.totalForce[i] * 1/o.mass*stepSize;
                    //std::cout << o.totalForce[i] << std::endl;
                }
            }
        }
        void printObjectCoordinates(){
            for(auto o: objects){
                for(int i = 0; i<3 ; i++){
                    std::cout << "x" << i+1 << ": " << o.coordinates[i] << ","; 
                }
                std::cout << std::endl;
            }
        }
        void printObjectVelocities(){
            for(auto o: objects){
                for(int i = 0; i<3 ; i++){
                    std::cout << "v" << i+1 << ": " << o.velocity[i] << ","; 
                }
                std::cout << std::endl;
            }
        }
        void printObjectIntoCSV(){
            
        }
};






int main(){

World myWorld = World(true, 9.81, 0.01);
myWorld.insertObject(Object(false, {0,0,0}, {0,0,0}, 1, 0, 0));

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();

myWorld.printObjectCoordinates();
myWorld.printObjectVelocities();

myWorld.update();


return 1;
}