#include "Camera.h"
#include "ResizeProcessor.h"
#include "BinaryProcessor.h"

// =============================================
// 카메라 이미지 처리 파이프라인 예제
//
// [전체 구조]
//   Camera
//     └── pipeline (vector)
//           ├── ResizeProcessor  : 1920x1080 → 640x480
//           └── BinaryProcessor  : 흑백 이진화 (threshold=128)
//
// [실행 흐름]
//   1. Camera 생성
//   2. 처리기 등록 (AddProcessor)
//   3. 프레임 수신 시뮬레이션 (실제론 카메라 SDK가 자동 호출)
//   4. 각 프레임마다 pipeline 순서대로 처리
//   5. Camera 소멸 → pipeline 메모리 자동 해제
// =============================================
int main() {
    // 카메라 객체 생성 (스택)
    Camera cam;

    // 처리기 등록 - new로 힙에 생성 후 포인터를 넘김
    // Camera 소멸자에서 자동으로 delete 해줌
    cam.AddProcessor(new ResizeProcessor(640, 480));
    cam.AddProcessor(new BinaryProcessor(128));

    // 프레임 3개 수신 시뮬레이션
    // 실제 카메라: SDK가 OnImageCallback을 자동 호출
    for (int i = 1; i <= 3; i++) {
        ImageData *frame = new ImageData(1920, 1080, 1, "frame_00" + to_string(i) + ".png");
        cam.OnImageCallback(frame);
        delete frame;  // 프레임 처리 후 메모리 해제
    }

    // cam 소멸 → Camera 소멸자 → pipeline 전체 해제
}
