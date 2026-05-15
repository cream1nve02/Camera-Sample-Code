# Camera Image Processing Pipeline

C++ 카메라 이미지 처리 파이프라인 예제 코드

상속, 가상함수, 동적 바인딩, 동적 메모리 할당 개념 학습용

---

## 파일 구조

```
├── ImageData.h           # 이미지 데이터 클래스
├── ImageProcessor.h      # 처리기 부모 클래스 (인터페이스)
├── ResizeProcessor.h/cpp # 크기 조절 처리기
├── BinaryProcessor.h/cpp # 이진화 처리기
├── Camera.h/cpp          # 카메라 및 파이프라인 관리
└── main.cpp              # 실행 진입점
```

---

## 실행 흐름

```
Camera 생성
  └── 처리기 등록 (AddProcessor)
        ├── ResizeProcessor (1920x1080 → 640x480)
        └── BinaryProcessor (threshold=128 이진화)

프레임 수신 (OnImageCallback)
  └── pipeline 순서대로 처리
        ├── [Resize] 1920x1080 → 640x480
        └── [Binary] threshold: 128 적용
```

---

## 핵심 개념

### 상속 & 순수 가상함수
```cpp
class ImageProcessor {
    virtual void Process(ImageData *img) = 0; // 자식이 반드시 구현
};

class ResizeProcessor : public ImageProcessor {
    void Process(ImageData *img) override { ... }
};
```

### 동적 바인딩
```cpp
// 부모 포인터로 묶어서 관리
vector<ImageProcessor*> pipeline;

// 실제 객체 타입에 맞는 Process 호출
pipeline[i]->Process(img); // ResizeProcessor면 Resize, BinaryProcessor면 Binary 실행
```

### 동적 메모리 할당
```cpp
// 픽셀 데이터를 힙에 할당
data = new unsigned char[width * height * channels];

// 소멸자에서 해제
delete[] data;
```

---

## 빌드 및 실행

```bash
g++ main.cpp ResizeProcessor.cpp BinaryProcessor.cpp Camera.cpp -o output.exe
./output.exe
```

---

## 새 처리기 추가 방법

1. `ImageProcessor`를 상속받는 클래스 작성
2. `Process` 함수 구현
3. `main.cpp`에서 `AddProcessor`로 등록

```cpp
class BlurProcessor : public ImageProcessor {
public:
    void Process(ImageData *img) override { ... }
};

cam.AddProcessor(new BlurProcessor);
```
