2024/03/26

## <p.6>

아래것들을 조절가능

* Amplitude shift keying
* Frequency shift keying
* Phase shift keying

## <p.7>

Signal element를 정하는게 쉽지 않다.

Signal element: 임의 설정하는 거임, 다양한 signal 모양(다른 amp, freq, phase)에 값붙이기

baud - signal이 얼마나 빨리 가는가

bit rate >= baud rate -> signal 하나에 1bit는 필요함 ㅇㅇ

4QAM = 걍 4개 signal 가져와서 signal 당 2bit 보내기

16Q = 4Q보다 전송 속도 2배 (2bit, 4bit)

64Q = 3배 (6bit)

2048Q = 5.5배 -> 오류가 생각보다 잘난다.





2024/04/02

## <p.12>

### ASK

carrier signal

carrier frequency

central frequency: 중심 대역폭

channel

ex) central frequency = 2.412GHz / bandwitdth = 20 MHz -> 2.402 ~ 2.422

## <p.13>

그냥 amplitude를 0으로 만들자 -> 근데 주파수 0이라 만든거랑 똑같은거 아님? -> ㅇㅇ 그러게

## <p.15>

### FSK

주파수 빨라졌다가 느려졌다가

잘안씀 -> 주파수 돈내고 사는데 여러개 한번에 쓰면 아깝다

## <p.17>

### PSK

위상을 다르게

끊어져 보이는것 가능함? -> 수식으로 구현 가능함

끊는 타이밍 어케암? -> 정해져 있음

## <p.19>

제일 저속: BPSK(binary PSK) -> 2개만 사용(0, 180)

모양개수 늘리면 여러개 한번에 가능

QPSK(quadrature): 4개(45, 135, -45, -135) -> 딴거 써도됨

## <p.21>

baud rate : 12 / 2 = 6Mbps

## <p.22>

ASK + PSK -> constellation diagram

원점으로 부터의 거리 = amplitude

그때의 각 = phase

## <p.23>

대충 그림으로 바꿔보자

점의 개수가 중요하다 -> 몇비트 보내는지 파악

## <p.25>

### QAM

= QPSK + ASK

16-QAM - 4bit -> 남들보다 2배 빠르지만 복원이 힘들다

SNR이 낮아지면 2배 속도라고 볼 수 없다.

## <p.27>

analog to analog

그럼 왜 아날로그를 굳이 왜 또 아날로그로 바꿈?

내가 원하는 carrier frequency랑 전송 frequency랑 다른거임 (라디오 주파수, 가청주파수 다르듯이)

amplitude(AM radio), frequency(FM radio), phase(얘는 어려움)

## <p.30>

AM - 10kHz 만큼은 떨어뜨려 줘야 한다.

## <p.32>

FM: 200kHz는 떨어뜨려 줘야 한다.
