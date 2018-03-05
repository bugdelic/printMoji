# printMoji
OSC で文字を受信して　印刷します。

<pre>
Endpoint : /moji
Port :  8282

0 : 0 or 1 
    0 : テキスト文字
    1 : 画像

1 : テキスト文字の場合、何か文字列
    画像の場合、pngがGood(未実装)

2 : R
3 : G
4 : B

RGBの指定は無くてもOK。GUIの方のデフォルトを利用。

exp)
oscer localhost 8282 /moji 0 脂肪
画像として一旦保存してlpでプリンタ出力です。

</pre>

画面GUI : screenshot.png

出力画像 : drawmoji.png

