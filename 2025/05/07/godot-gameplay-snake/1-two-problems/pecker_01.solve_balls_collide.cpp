#include <cmath>

struct ball {
	double px, py, pz; // position
	double r;          // shape
	double vx, vy, vz; // velocity
};

void solve_2balls_collide(ball& a, ball& b) {
	double dx = b.px - a.px;
	double dy = b.py - a.py;
	double dz = b.pz - a.pz;
	double distance = sqrt(dx * dx + dy * dy + dz * dz);

	if (distance < a.r + b.r) {
		double overlap = a.r + b.r - distance;
		double nx = dx / distance;
		double ny = dy / distance;
		double nz = dz / distance;
		a.px -= nx * overlap / 2.0;
		a.py -= ny * overlap / 2.0;
		a.pz -= nz * overlap / 2.0;
		b.px += nx * overlap / 2.0;
		b.py += ny * overlap / 2.0;
		b.pz += nz * overlap / 2.0;
	}

}

// 碰撞
// 运动
// 观测

struct hit {
	// 力臂
	// 质心
	// 支点
	// 
};

void solve_hit_events(hit* events) {

}
