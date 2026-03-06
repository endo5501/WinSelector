## 1. 設定値の追加

- [x] 1.1 Settingsクラスにアイコンリフレッシュ間隔の設定値（iconRefreshIntervalMs、デフォルト60000）を追加する
- [x] 1.2 WinSelectorConfig::MainWindow名前空間にiconRefreshIntervalMs()アクセサを追加する

## 2. アイコンキャッシュ無効化タイマーの実装

- [x] 2.1 MainWindowにm_iconRefreshTimerメンバ変数（QTimer*）を追加する
- [x] 2.2 MainWindowのコンストラクタでm_iconRefreshTimerを初期化し、iconRefreshIntervalMsの間隔で開始する
- [x] 2.3 タイマーのtimeoutシグナルをWin32Utils::clearIconCache(nullptr)の呼び出しに接続する

## 3. テスト

- [x] 3.1 アイコンキャッシュ無効化タイマーの動作を確認するテストを作成する（キャッシュクリア後にアイコンが再取得されること）
- [x] 3.2 ビルドして動作確認する（アイコンが60秒ごとに更新されること）
