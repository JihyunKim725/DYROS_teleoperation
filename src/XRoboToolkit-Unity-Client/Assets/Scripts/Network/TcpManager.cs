using System;
using System.Text;
using UnityEngine;

namespace Robot.V2.Network
{
    public class TcpManager : MonoBehaviour
    {
        private TcpServer tcpServer;
        // 수정 1: 변수명을 tcpClient로 변경하고 인스턴스화 (변수 혼용 방지)
        private TcpClient tcpClient = new TcpClient(); 

        public int port = 13579;

        private string serverTag = "TcpManager - TcpServer(C#)";
        private string clientTag = "TcpManager - TcpClient(C#)";

        public System.Action<byte[]> OnServerReceived;
        public System.Action<string> OnClientReceived;

        public static TcpManager Instance { get; private set; }

        // 수정 2: 프로퍼티에서 사용하는 변수명 일치
        public TcpServer TCPServer => tcpServer;
        public TcpClient TCPClient => tcpClient;

        private void Awake()
        {
            if (Instance == null)
            {
                Instance = this;
                DontDestroyOnLoad(gameObject);
            }
            else
            {
                Destroy(gameObject);
            }
        }

        void Start()
        {
            tcpServer = TcpServer.CallbackProxy;

            tcpServer.OnServerStarted += OnServerStarted;
            tcpServer.OnClientDisconnected += OnClientDisconnected;
            tcpServer.OnDataReceived += OnDataReceived;
            tcpServer.OnError += OnError;
            tcpServer.OnServerStopped += OnServerStopped;

            tcpClient = TcpClient.CallbackProxy;
            tcpClient.OnConnected += TcpClientOnOnConnected;
            tcpClient.OnDisconnected += TcpClientOnOnDisconnected;
            tcpClient.OnDataReceived += TcpClientOnOnDataReceived;
            tcpClient.OnError += TcpClientOnOnError;

#if !UNITY_EDITOR
            StartServer();
#endif
        }

        private void OnDestroy()
        {
            if (tcpServer != null) {
                tcpServer.OnServerStarted -= OnServerStarted;
                tcpServer.OnClientDisconnected -= OnClientDisconnected;
                tcpServer.OnDataReceived -= OnDataReceived;
                tcpServer.OnError -= OnError;
                tcpServer.OnServerStopped -= OnServerStopped;
            }

            if (tcpClient != null) {
                tcpClient.OnConnected -= TcpClientOnOnConnected;
                tcpClient.OnDisconnected -= TcpClientOnOnDisconnected;
                tcpClient.OnDataReceived -= TcpClientOnOnDataReceived;
                tcpClient.OnError -= TcpClientOnOnError;
            }
        }

        #region Server

        private void OnError(string msg) => Utils.WriteLog(serverTag, msg);

        private void OnDataReceived(byte[] data, int length)
        {
            try
            {
                EventExecutor.ExecuteInUpdate(() => { OnServerReceived?.Invoke(data); });
                Utils.WriteLog(serverTag, $"data: {data.Length} length: {length}");
            }
            catch (Exception e)
            {
                Utils.WriteLog(serverTag, $"exception: {e.Message} {e.StackTrace}");
            }
        }

        private void OnClientDisconnected() => Utils.WriteLog(serverTag, "Disconnected");
        private void OnServerStopped() => Utils.WriteLog(serverTag, "Stopped");
        private void OnServerStarted(int port) => Utils.WriteLog(serverTag, $"Started: {port}");

        public void StartServer()
        {
            // 수정 3: CS0176 방지를 위해 클래스 이름 'TcpServer' 사용
            TcpServer.StartTCPServer(port, OnServerStarted);
        }

        public void StopServer()
        {
            Utils.WriteLog(serverTag, $"Stopping Server");
            // 수정 4: 클래스 이름 'TcpServer' 사용
            TcpServer.StopServer();
            Utils.WriteLog(serverTag, $"Stopped Server");
        }

        #endregion

        #region Client

        private void TcpClientOnOnError(string arg1, Exception arg2) => Utils.WriteLog(clientTag, $"{arg1}\t{arg2}");

        private void TcpClientOnOnDataReceived(byte[] data, int length)
        {
            OnClientReceived?.Invoke("");
            Utils.WriteLog(clientTag, $"data: {data} length: {length}");
        }

        private void TcpClientOnOnDisconnected() => Utils.WriteLog(clientTag, "Disconnected");
        private void TcpClientOnOnConnected() => Utils.WriteLog(clientTag, "Connected");

        public void StartClient(string host)
        {
            // 수정 5: 오타(=.) 제거 및 클래스 이름 'TcpClient' 사용
            TcpClient.ConnectToServer(host, port, TcpClientOnOnConnected);
        }

        public void StopClient()
        {
            Utils.WriteLog(serverTag, $"Disconnecting Client");
            // 수정 6: 클래스 이름 'TcpClient' 사용
            TcpClient.Disconnect();
            Utils.WriteLog(serverTag, $"Disconnected Client");
        }

        public void ClientSend(string s)
        {
            // 수정 7: 클래스 이름 'TcpClient' 사용
            if (TcpClient.Status == ClientStatus.Connected)
            {
                Utils.WriteLog(clientTag, $"Send: {s}");
                TcpClient.Send(Encoding.UTF8.GetBytes(s));
            }
            else
            {
                LogWindow.Error("Client is not connected. Cannot send data.");
            }
        }

        public void ClientSend(byte[] data)
        {
            // 수정 8: 클래스 이름 'TcpClient' 사용
            if (TcpClient.Status == ClientStatus.Connected)
            {
                Utils.WriteLog(clientTag, $"Send: {data.Length} bytes");
                TcpClient.Send(data);
            }
            else
            {
                LogWindow.Error("Client is not connected. Cannot send data.");
            }
        }

        #endregion
    }
}