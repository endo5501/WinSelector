## ADDED Requirements

### Requirement: Periodic icon cache invalidation
システムは一定間隔でアイコンキャッシュ全体を無効化しなければならない（SHALL）。これにより、次回のウィンドウリフレッシュ時にすべてのウィンドウアイコンがWin32 APIから再取得される。

#### Scenario: Icon cache is cleared at configured interval
- **WHEN** アイコンキャッシュ無効化タイマーが発火する（デフォルト60秒間隔）
- **THEN** アイコンキャッシュ全体がクリアされる

#### Scenario: Icons are re-fetched after cache invalidation
- **WHEN** アイコンキャッシュがクリアされた後に通常のウィンドウリフレッシュが実行される
- **THEN** 各ウィンドウのアイコンがWin32 APIから新たに取得され、キャッシュに再保存される

#### Scenario: Failed icon is recovered on next refresh after invalidation
- **WHEN** 初回のアイコン取得に失敗したウィンドウが存在し、アイコンキャッシュが無効化された後にリフレッシュが実行される
- **THEN** 当該ウィンドウのアイコンが再取得され、アイコンが利用可能であれば正しく表示される

### Requirement: Icon refresh interval configuration
アイコンキャッシュ無効化の間隔はコンフィグ値として定義されなければならない（SHALL）。

#### Scenario: Default interval is approximately 60 seconds
- **WHEN** アプリケーションがデフォルト設定で起動する
- **THEN** アイコンキャッシュ無効化タイマーの間隔は60000ミリ秒である

### Requirement: Icon refresh timer lifecycle
アイコンキャッシュ無効化タイマーはMainWindowのライフサイクルに従わなければならない（SHALL）。

#### Scenario: Timer starts with application
- **WHEN** MainWindowが初期化される
- **THEN** アイコンキャッシュ無効化タイマーが開始される

#### Scenario: Timer is independent of window refresh timer
- **WHEN** アイコンキャッシュ無効化タイマーが発火する
- **THEN** ウィンドウリフレッシュタイマー（2秒間隔）には影響を与えない
