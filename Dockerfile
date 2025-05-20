# ベースイメージ
FROM ubuntu:25.10

# パッケージリスト更新＆必要パッケージのインストール
RUN apt-get update && \
    apt-get install -y \
      gcc \
      make \
      libreadline-dev \
      valgrind \
    && rm -rf /var/lib/apt/lists/*

# ホストのカレントディレクトリを /workspace にマウントして使う想定
WORKDIR /workspace

# デフォルト起動コマンド
CMD ["bash"]
