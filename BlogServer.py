import http.server
import os

abspath = os.path.abspath(__file__)
dname = os.path.dirname(abspath)
os.chdir(dname)

PORT = 8000

class NoCacheHTTPRequestHandler(
    http.server.SimpleHTTPRequestHandler
):
    def send_response_only(self, code, message=None):
        super().send_response_only(code, message)
        self.send_header('Cache-Control', 'no-store, must-revalidate')
        self.send_header('Expires', '0')

if __name__ == '__main__':
    http.server.test(
        HandlerClass=NoCacheHTTPRequestHandler,
        port=PORT,
        bind="0.0.0.0"
    )
