#include <chrono>

void handle_input() {}
void fixed_update(double delta) {}
void update(double delta) {}
void render(double delta) {}

double get_frame_delta() {
	using clock = std::chrono::steady_clock;
	using seconds = std::chrono::duration<double>;
	using timepoint = std::chrono::time_point<clock>;

	static timepoint last = clock::now();
	timepoint curr = clock::now();
	seconds delta = curr - last;
	last = curr;

	return delta.count();
}

int main(int argc, char* argv[]) {
	bool running = true;

	double frame_delta = 0.0;
	double fixed_delta = 1.0 / 60.0; // 60 FPS
	double accumulator = 0.0;

	while (running) {
		frame_delta = get_frame_delta();
		accumulator += frame_delta;

		handle_input();
		update(frame_delta);
		while (accumulator >= fixed_delta) {
			accumulator -= fixed_delta;
			fixed_update(fixed_delta);
			render(fixed_delta);
		}
	}
	return 0;
}
