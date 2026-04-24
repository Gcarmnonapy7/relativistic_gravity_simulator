#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <cmath>
#include <vector>

struct Vec3
{
    double x, y, z;
   
    // Constructors
    Vec3() : x(0), y(0), z(0) {}
    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    // Operator overloads
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
   
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }

    Vec3 operator*(double s) const { return Vec3(x * s, y * s, z * s); }

    Vec3 operator/(double s) const { return Vec3(x / s, y / s, z / s); }

    // Length of the vector
    double length() const { return std::sqrt(x * x + y * y + z * z); }
 
};

struct Particle 
{
    Vec3 position;
    Vec3 velocity;
    double mass;
    bool alive;
    float colot_r, colot_g, colot_b; // Visual representation

    Particle(const Vec3& position, const Vec3& velocity, double mass)
        : position(position), velocity(velocity), mass(mass), alive(true), colot_r(1.0f), colot_g(1.0f), colot_b(1.0f) {}

};

class GravitySimulator 
{
    private: 
        std::vector<Particle> particles;
        double mass;
        Vec3 position;
        double G; // Gravitational constant
        double c; // Speed of light 

        double schwarzschild_radius() const {}
        double time_dilation(const Vec3& particle_position) const {}
        double relativistic_velocity(const Vec3& particle_velocity) const {}
        Vec3 relativistic_correction(const Vec3& particle_velocity) const {}

    public:

        GravitySimulator();

        void add_particle(const Vec3& position, const Vec3& velocity, double mass, 
                          float r=1.0f, float g=1.0f, float b=1.0f);
        
        void compute_forces();
        void integrate(double delta_time);
        void handle_collisions();
        void handle_event_horizon_crossing();
};

#endif // PHYSICS_HPP