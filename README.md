# Tetris
C++ Tetris Games

# PDCurses library
아래의 페이지에서 `pdc34dll.zip`를 다운로드
http://sourceforge.net/projects/pdcurses/files/pdcurses/3.4/

다운로드 받은 압축파일을 C:\pdcurses\ 폴더에 풀기 (폴더가 없으면 만들면 됨)

C:\pdcurses\pdcurses.dll 파일  C:\Windows\system 폴더로 이동

# PDCurses library 적용
1. Visual Studio 실행
2. 프로젝트 생성
3. 메뉴 – [프로젝트] – [속성] 클릭

[구성속성] – [C/C++] – [일반] – [추가 포함 디렉토리] – [편집] 에서 C:\pdcurses 추가
[구성속성] – [링커] – [일반] – [추가 라이브러리 디렉토리] – [편집] 에서 C:\pdcurses 추가
[구성속성] – [링커] – [입력] – [추가 종속성] – [편집] 에서 pdcurses.lib 추가
