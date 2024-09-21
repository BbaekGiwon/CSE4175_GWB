# ch.4

2024/04/02

## <p.2>

네트워크의 고민: 오류를 어떻게 처리할 것인가?, 자원을 어떻게 분배할 것인가?

Physical & Data Linker -> 1 대 1 통신만 다룸

device, host, node: 통신에 참여한 기기

## <p.4>

Error: 0을 1로, 1을 0으로 해석

## <p.6>

n-bit error

## <p.7>

* Error detection
* Error correction

## <p.8>

ex) 송신 10101101 -> 수신 10101100

만약 channel이 8bit를 전송, 99.9% 오류가 1bit 이하

예로 오류 검출은 4개씩 끊어서 한번에 두번 보냄 -> 앞뒤가 다르면 오류

하여간 비트를 더 보냄-> 나올수 없는 비트 패턴이 등장하면 오류 검출

## <p.11>

dataword: 원레 데이터

codeword: 바뀐놈

redundancy: 추가된 비트

## <p.13>

01101100 -> 011101110000

table 보고 하면 됨

근데 받은 놈이 111을 받았다 -> table에 없네? -> 오류고만

근데 만약 2bit가 오류가 난다? 01 -> 011(송신) -> 000(수신) -> 0 -->이런 경우처럼 오류 검출을 못할 수도

## <p.19>

2bit -> 5bit

2bit error까지 검출 가능

redundeny가 늘어날 수록 오류 검출 능력이 증가한다. but 속도 감소





2024/04/04

## 복습

* Digital -> Digital : 10101 -> 위아래위아래위, line coding, baseband transmission
* Digital -> Analog: bandpass, broadband, carrier frequency 변형, ASK, shift key, 16QAM
* Analog -> Digital: PCM
* Analog -> Analog: 다른 carrier frequency를 이용, FM

정리해보자.

## p.20

2bit 보낼때 5bit로 바꿔서 보내면 2bit 에러 발생해도 검출 가능 -> but 전송속도 느려짐

## p.17

n-bit 오류검출 = 100%로 n-bit오류 검출

즉 000의 모든 오류의 경우의 수 (001, 010, 100)을 모두 따져봐야한다.

## p.24

### Hamming distance

바꿔줘야하는 비트 수

## p.25

minimum hamming distance: 다 따져봤을 때 최소로 바꿔야 하는 bit수

표에서는 2이다. -> 그럼 1 bit 오류 검출능력을 가진다.

## p.26

표의 minimum hamming distance = 3 -> 2 bit 오류 검출능력을 가진다.

## p.31

### 오류수정

00000 오류발생 -> 10000 -> 이놈과 codeword의 hamming distance -> 00000(1), 01011(4), 10101(2), 11110(3) -> 그럼 합리적으로 00000 아닐까?

## p.30

000 오류발생 -> 100 -> 이놈과 codeword의 hamming distance -> 000(1), 011(3), 101(1), 110(1) -> 어 이럼 모르겠다.

## p.32

내가 수정하고자 하는 bit수가 hamming distance의 두배보다 작아야 한다. -> MHD > 2 * n

검출할라는 bit수가 hamming distance보다 작으면 가능하다. -> MHD > n

## p.37

MHD=4

-> detect -> 3까지

-> correct -> 1까지

## p.39

### Linear block code

두개를 뽑아서 XOR 했더니 이미 있는 것이면 linear block code

## p.42

MHD = 제일 적은 1의 개수 // 여기선 3

## p.43

1 bit(parity bit) 추가

even parity : parity bit를 활용하여 짝수개수의 1을 가지도록 한다.

## p.44

1 bit 추가해서 MHD를 2로 만들었다.

비트 오류율 = 비트마다 오류가 발생할 확률

9 -> 10: 전송율 90% -> 그러나 오류가 발생하면 10개중 1개를 찾아야함

2 -> 3: 전송율 67% -> 오류 발생시 3개중 1개 찾기

## p.46

even parity check: 10011, 10110 -> 오류라고 판단

## p.47

00110: 오류검출 X

01011: 오류검출 O

## p.48

1, 3 bit error -> 검출 O

2, 4 bit error -> 검출 X

MHD가 2이므로 1 bit error 검출은 확정이다. 이에 3, 5, 7....도 가능하므로 개꿀 ㅋㅋ

## p.50

2-dimensional parity

row, column 둘다 짝수로 맞춰줌

## p.51

1bit error 발생 -> row, column 둘다 검출 됨 -> 위치 특정 가능 -> 수정 가능

2bit error 발생 -> row, column 둘 중 하나는 오류 -> 수정은 안됨

3bit error 발생 -> 검출 가능, ㄴ자로 오류 생기면 엄한거 수정할듯

4bit error 발생 -> 검출 가능 X

## p.54

### Hamming code

목표: MHD = 3 -> 1개 수정가능

## p.55

Hamming (7,4) code -> 방법은 여러가지 -> 시험문제는 강의자료 방법 따라서

최소 3비트는 붙여야 하더라!







2024/04/09

## p.56

Hamming (7,4) code 

2의 지수승은 check bit

c1 : 번호의 마지막 bit가 1인 애들 = & 연산 후에 c1의 번호(1) 이 나오는 애들

c2: 10, 11 인 애들  



ex) 1011 -> 0110011

ex) 0101 -> 0100101

## p.61

벤다이어그램에 속한게 영향을 미치는 비트

mhd가 3이면 ~2검출, 1수정

## p.62

0000 -> 0000000

0011 -> 1000011

1010 -> 1011010

1110 -> 0010110

## p.63

hamming (7,4)의 mhd = 3

bit를 수정하는 코드를 만들고 싶으면 redundency 3개 이상필요

## p.67

voting: data를 3배로 불림 0 -> 000 / 1->111

010이면 0이 많으므로 0으로 수정

근데 효율 구림 33.3%

## p.69

hamming(7,4), hamming(15,11), hamming[31,26], hamming(63,57)

-> hamming(2^N-1, 2^N-1-N)



ex) 10110101100

| <1>  | <0>  | 1    | <0>  | 0    | 1    | 1    | <1>  | 0    | 1    | 0    | 1    | 1    | 0    | 0    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| <1>  |      | 1    |      | 1    |      | 2    |      | 2    |      | 2    |      | 3    |      | 3    |
|      | <0>  | 1    |      |      | 2    | 3    |      |      | 4    | 4    |      |      | 4    | 4    |
|      |      |      | <0>  | 0    | 1    | 2    |      |      |      |      | 3    | 4    | 4    | 4    |
|      |      |      |      |      |      |      | <1>  | 0    | 1    | 1    | 2    | 3    | 3    | 3    |

## p.70

Efficiency rate는 커질수록 증가한다

4/7, 11/15, 26/31, 57/63

-> 근데 1비트만 오류난다는 보장이 없어서 고려해야함

## p.74

### Checksum

다 더한 값을 마지막에 추가해서 보낸다.

## p.75

다 더한 값을 음수로 바꿔서 보내자 -> 다 더했을때 0나오는게 편하더라

ex) 0111/1011/1100/0000/0110

-> checksum이 36인데 이거는 4bit가 아님

## p.76

### Wrapped Sum

36 = 100100 -> 4개씩 잘라서 10/0100 -> 둘이 더함 0110 = 6 -> 이거 음수여야 하잖아 -> 1's compliment -> 1001=9

-> 실제로 붙이는건 1001 -> 0111/1011/1100/0000/0110/1001 이됨 -> 더하면 101101 = 45 -> wrapped sum -> 10 + 1101 = 1111 = 0(1's compliment) -> 오류없음



ex) 0111/1011/1101/1000/0110 -> 다 더하면 45 = 101101 -> wrapped sum 10 + 1101 = 1111 -> 1's compliment -> 0000 -> 0111/1011/1101/1000/0110/0000을 보내면 됨 -> 검사하면 다 더했을 때 45 -> 오류없음

->결론적으로 마지막꺼는 더했을때 45 나오는 숫자 고르면 됨

## p.78

근데 다 더했더니 63나옴

63 = 111111 -> wrapped sum -> 11 + 1111 = 10010 -> 4bit 아니므로 wrapped sum 한번 더 -> 1 + 0010 = 0011





2024/04/11

## p.85

### Modulo 

나누고 나머지

modulo-5

-> 3+2=0

-> 2-3=4

## p.87

modulo-2 는 덧셈이든 뺄셈이든 XOR 연산과 같다.

## p.88

### CRC

Cyclic Redundancy Check

divisor = 1011

dataword = 1001 -> 4bit로 나누므로 1001000 -> 1001000 / 1011 = 1010(몫), 110(나머지)

code word = dataword + remainder

code word / divisor == 0 -> 오류없음으로 판단

허나 parity, check sum , crc 모두 오류 검출에 실패할 수 있다.

## p.92

오류 발생 케이스

1100010 이면 오류안남

divisor, dataword 모두 크기조정 가능

## p.93

binary -> polynomials 가능

## p.94

divisor = 1011

dataword = 1001

-> 대충 비슷하게 하면 됨

## p.95

dataword: M(x)

divisor: g(x)

codeword: T(x)

-> T(x) is divisible by g(x) -> 오류 X

## p.96

수신자가 받고(T'(x)) divisor로 나눠봤을때 나머지가 0이면 오류 없다고 판단

## p.97

오류를 e(x)로 표현

T'(x) = T(x) + e(x)

T(x) = 1001110

T'(x) = 1000110

-> e(x) = 0001000

e(x) == 0 -> 오류 없음

e(x) != 0  && T'(x)%g(x)==0 -> 오류 검출 실패 = (g(x) % e(X) == 0)

-> 고로 오류 패턴이 무엇인지 관건이다. <- 이게 오류 검출 능력(performance)을 좌우

-> g(x)를 바꿔서(이것만 컨트롤 가능) 오류패턴을 골라보자 -> g(x)가 잘 안 나누어 떨어지게

## p.99

b: 1000 -> 1bit 오류가 발생했는데 검출 못함

그래서 divisor가 잘 안나눠져야 함

## p.101

burst error: 어떤 구간안에 오류가 나는 것

4bit 오류났어도 구간길이는 8bit임 -> 8bit burst error

## p.102

divisor = x^6 + 1 = 1000001 -> length가 7 이므로

-> 6이하의 burst error는 검출

-> 7 burst error: 1경우(1000001)만 검출이 안되므로 확률은 31/32 

-> 8 burst error: 1경우(11000011)만 검출이 안되므로 63/64

-> 9 burst error: 

