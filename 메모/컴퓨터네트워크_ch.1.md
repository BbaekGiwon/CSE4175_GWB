2024/03/07

## <p.7>

Frequency(f) - 1초에 몇번 왔다갔다? - 주파수

Period(T) - 한번 왔다갔다에 얼마나 걸림?

## <p.14>

위상: 위치

위상이 다르다면 f,T 같아도 다른 신호

## <p.17>

wavelength(λ) - 파장

2GHz 신호의 주기 = T = 1/2*10^9, λ = (1/2 *10^9) * (3*10^8)m/s = 0.15m  (거리 = 속력(대충 광속) * 시간)

밀리미터파: 파장이 밀리미터임 - 대충 매우 고주파수임

1cm인 신호의 주파수 = 30GHz

## <p.19>

Time domain: x축이 시간

Frequency domain: x축이 주파수

## <p.22>

time domain은 사인 웨이브의 합인데 Frequency domain은 작대기 몇개라 알아보기 쉽다.



고주파 - 직진성 큼/회절성 약함 - 잘안터짐

## <p.30>

Bandwidth: composite signal의 f 범위, 중간에 빵꾸나도 걍 진행시킴

## <p.33>

95.9MHz - 중심주파수

95.8~96.0 MHz 까지 쏴줌 - 200KHz의 Bandwidth

## <p.34>

라디오 주파수 MHz, but 목소리는 0 ~ 4000 -> 변환필요(Modulation)

* AM - 진폭을 이용한 변환 - Amplitude Modulation -> 잡음 복원이 힘들고 어쩌고
* FM - 주파수를 이용한 변한 - Frequency Modulation

## <p.36>

Digital signals - discreate

bps: 1초에 몇 비트를 전송? (bit per sec) - 인터넷 속도





2024/03/12

## <p.37>

0,1 구분 방법 - 사인 웨이브 잘 합쳐서 디지털 시그널처럼 만들면 됨

1초에 8개 보냈으니까 8bps

2개의 준위 - 1비트씩

## <p.38>

준위가 4개라면 2비트를 한번에 받을 수 있다.

이건 16bps

## <p.41>

80 * 24 * 100 * 8 = 1536000 bit

1.536Mbps

## <p.42>

1920 * 1080 * 30 * 24 = 1492992000

1.5Gbps 필요

실제로는 압축(안바뀌면 전송X)해서 그 정도는 안 필요

## <p.45>

대충 사인웨이브 합쳐서 만든거 해체하면 Frequency domain -> 오른쪽 합치면 왼쪽 모양 나옴

연속적인 Frequency domain -> Time domain의 하나의 패턴

## <p.47>

디지털의 강점: 대충 0,1 만 구분하면 되서 조금 찌그러져도 복구 가능

Baseband Transmission: 기저대역전송 - 높은 주파수는 짜름(Low-pass channel), 그래서 0부터 어디까지 주파수 짜를지를 정하는게 Baseband

## <p.49>

특정주파수만 통과시키므로 왜곡 발생 -> 그러나 0,1은 구분 가능하므로 노상관

## <p.51>

3bit 전송 - 8개 패턴 - 사인웨이브 합으로 만들어보자 - p.52

## <p.52>

대충 근사시키는 것

[주파수 0, 주파수 @, 주파수 @ * 2] 이렇게 3개만 필요

주파수가 높으면 전송속도 빠름

## <p.53>

[첫번째 짤] digital Nbps - Analog N/2Hz -> 010이 3/2이므로 2번 보내면 6bit 가는 것임 즉 3번 왕복에 6bit

즉 나의 Bandwidth가 0에서 시작 500KHz이면 1MHz까지 위와 같은 방법으로 보낼 수 있음

주파수 여러 개 섞어서 더 digital과 비슷하게 만듦 -> 왜곡에 대비, 신뢰성 높이기

즉 속도와 신뢰성 trade off

## <p.55>

### Summary

정확히 보낼려면 무한대의 주파수 필요 - 그거 안되니까 짜름 - 짜를때 최소 N/2는 필요

## <p.57>

Band-pass channel - 0부터가 아니라 f_1 ~ f_2인거

## <p.59>

진폭이 큰거를 1, 작은거를 0으로 설정

## <p.60>

Baseband(digital) vs Broadband(analog)

모뎀: modulation/demodulation 해주는거

## <p.63>

신호가 잘 안터지는 3가지 경우

## <p.64>

Attenuation: 신호의 세기가 거리가 멀어짐에 따라 점점 줄음 -> 증폭기

## <p.65>

dB : 두 신호의 파워의 비 * 10

log_10 2 =: 0.3

log_10 0.5 =:  -0.3

3dB가 줄었다 -> 반이 줄었다.

반감기

10 dB - 10배

## <p.68>

대충 dB끼리 더할 수 있어서 계산 편함

## <p.69>

dBm: 절대값 (대충 분모가 1)

Pm: 밀리와트 개념

200mW = 23dBm

500mW = 27dBm







2024/03/14

## <p.69>

핸드폰(보낼 때): 23dBm - 업링크

기지국(받을 때): 30~40dBm - 다운링크

왜 전력이 다르게? -> 빠떼리와 전원의 차이

핸드폰: 기지국이랑 가까우면 약하게 쏨 - > 빠떼리 절약

## <p.70>

5km -> 1.5dB감소

P1 10dBm = 10mW

P2 30dBm = 1000mW

둘의 신호비교: p2/p1 = 100

비율을 비교할때는 20dB라고 해야함 (dBm아님)



23dBm 송신 -> -60dBm 수신

83dB만큼의 신호 감쇠

## <p.71>

주파수, 진폭 왜곡

라디오의 경우 주파수 바뀜 -> 딱붙어 있으면 중첩, 간섭 -> 단순하게 띄어놓으면 됨(가드밴드)

## <p.72>

signal: 원하는 거

noise: 필요 없는거, 간섭을 일으키는 것, 비슷한 주파수인 경우

주파수: 라이센스 대역 & 비라이센스 대역

* 라이센스: 경매, 공공 - LTE, 5G
* 비라이센스: 대충 누가 써도 노상관 - Wifi(2.4, 5GHz), 블루투스(2.4GHz) -> 간섭 뒤짐

wifi: 이동고려 X

## <p.73>

SNR = signal power / noise power

S = -60dBm = 10^-6 * 1mW

N = -80dBm

SNR = S/N = 20dB

## <p.74>

S = 10mW

N = 1uW

SNR = 40dB

## <p.75>

noise 없으면 SNR 무한대

floor noise: -100dBm = 10^-10 * 1mW

강전계, 중전계, 약전계: [, -50~-80, -80] -> 와이파이 신호세기 등

## <p.76>

SNR이 어느정도 높아야 한다. - 낮으면 복구 X

## <p.79>

Data rate = 2 * B * log_2 L

B: bandwidth - 체널의 대역폭이 전송속도와 비례

L: number of signal levels - 준위 많이 쓰면 속도 증가 (준위 4 -> 2bit 한번에)

준위를 많이 쓴다 -> 같은 진폭안에서 많이 쪼갰다. -> noise 끼면 좆됨 ㅋㅋ

상황에 따라서 준위 개수 조절 - 잘터지면(SNR이 높으면) 준위 많이 가능

## <p.81>

2 * 3000 * log_2 4 = 12000

## <p.83>

C = B * log_2 (1+SNR)

SNR 커지면 오류률 줄어듬

맨 오른쪽이 준위 늘려놓은거

SNR이 20dB면 파랑이나 초록이 고르자

SNR이 높으면 전송속도(c)가 왜 늘어남? -> 준위 높은거 쓸수 있어서 빨라짐

## <p.87>

C = B * (SNR_dB / 3) <- 근사치

SNR이 log 스케일이다보니 바꾸는거 귀찮음 ㅇㅇ





2024/03/19

## <p.89>

bandwidth: 최대~최저 주파수 사이, Hz, 때에 따라서는 최대 전송속도(=capacity)

구분은 단위로 - Hz: 주파수, bps: 전송속도

## <p.90>

Throughput: 보내고자 하는 데이터(필요없는거 말고)가 얼마나 빨리 도착했는가

이것저것 붙여서 실제 데이터보다 커짐 /like 택배 상자+주소스티커/ 붙인거는 받고 나서 버림

따라서 Throughput < Bandwidth이다.

## <p.91>

한비트를 보냄 -> 도착지마다 경과 시간 다르게 발생 -> delay 때문

첫 비트를 보냄 ~ 마지막 비트 받음

## <p.92>

* Transmission delay: 보낼 때 첫 비트와 마지막 비트 사이의 시간
* propagation delay: 출발해서 도착할때까지의 시간
* Queuing delay: 줄서서 보내질때까지 기다리는 시간
* Processing delay: 여러가지 정보(주소)를 덕지덕지 붙이는 시간(보내고 받는데 둘 다 필요)

transmission delay = # of bits / bandwidth(bps)

propagation delay = 송신자 - 수신자 거리 (diastance) / (speed)

## <p.93>

짤 함 살펴보기

## <p.94>

12000 * 10^3 / 2.4 * 10^8) = 0.05s = 50ms <- 교제에 오타있음, 이게 맞음

## <p.95>

(2500 * 8) / 10^9 = 20 * 10^-6 = 20ns

-> propagation time이 dominant factor이다

## <p.97>

거 = 속 * 시

bandwidth * delay = 5bit



