## Why

WindowTileに表示されるアイコンは、Win32Utils::getWindowIcon()で取得された後にアイコンキャッシュ(s_iconCache)に保存され、以降はキャッシュから返される。そのため、初回取得時にアイコン取得に失敗した場合（タイミングの問題等）やアプリケーションがアイコンを動的に変更した場合（通知バッジ、状態変化等）でも、古いアイコンが表示され続ける。

## What Changes

- アイコンキャッシュに定期的な無効化（invalidation）の仕組みを追加する
- 約60秒ごとにアイコンキャッシュをクリアし、次回のウィンドウリフレッシュ時にアイコンを再取得させる
- 既存の2秒ごとのウィンドウリフレッシュサイクルはそのまま維持する

## Capabilities

### New Capabilities
- `icon-cache-invalidation`: アイコンキャッシュの定期的な無効化機能。一定間隔でキャッシュをクリアし、アイコンの再取得を促す。

### Modified Capabilities

(なし)

## Impact

- `src/win32utils.cpp`: アイコンキャッシュ（s_iconCache）のクリアタイミングに関わる
- `src/mainwindow.cpp`: 定期的なキャッシュ無効化のタイマー管理
- `src/config.h`: アイコン更新間隔の設定値追加（可能性あり）
